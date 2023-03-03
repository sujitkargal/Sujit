<!-- HTML code for the TODO app -->
<h1>TODO App</h1>

<!-- Form to add a new task -->
<form method="post" action="tasks.php">
  <label for="task_name">Add Task:</label>
  <input type="text" name="task_name" required>
  <button type="submit" name="add_task">Add</button>
</form>

<!-- List of pending tasks -->
<h2>Pending Tasks</h2>
<ul>
  <?php while ($row = $pending_result->fetch_assoc()) : ?>
    <li><?php echo $row['task_name']; ?>
      <a href="tasks.php?complete_task=<?php echo $row['id']; ?>">Complete</a>
      <a href="tasks.php?delete_task=<?php echo $row['id']; ?>">Delete</a>
    </li>
  <?php endwhile; ?>
</ul>

<!-- List of completed tasks -->
<h2>Completed Tasks</h2>
<ul>
  <?php while ($row = $completed_result->fetch_assoc()) : ?>
    <li><?php echo $row['task_name']; ?></li>
  <?php endwhile; ?>
</ul>
